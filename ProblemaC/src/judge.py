#!/usr/bin/env python3
import sys, subprocess, random, select

NUM_TESTS    = 700
MAX_QUERIES  = 100
READ_TIMEOUT = 5.0   # seconds

def safe_readline(stdout, timeout=READ_TIMEOUT):
    fd = stdout.fileno()
    ready, _, _ = select.select([fd], [], [], timeout)
    if not ready:
        return None
    return stdout.readline()

def run_test(sol_cmd, log, test_id):
    sx = random.randint(-10**8, 10**8)
    sy = random.randint(-10**8, 10**8)
    r  = random.randint(0, 10**7)
    while True:
        ax = random.randint(-10**8, 10**8)
        ay = random.randint(-10**8, 10**8)
        if not (sx - r <= ax <= sx + r and sy - r <= ay <= sy + r):
            break

    proc = subprocess.Popen(sol_cmd,
                            stdin=subprocess.PIPE,
                            stdout=subprocess.PIPE,
                            stderr=subprocess.DEVNULL,
                            close_fds=True)
    try:
        queries = 0

        def kill_and_log(msg):
            log.write(f"Test {test_id}: {msg}\n")
            try: proc.kill()
            except: pass

        # send Arenópolis
        proc.stdin.write(f"{ax} {ay}\n".encode()); proc.stdin.flush()

        while True:
            line = safe_readline(proc.stdout)
            if line is None:
                kill_and_log("HANG (no response in 5s)")
                return -1
            line = line.decode().strip()

            if line.startswith('?'):
                queries += 1
                if queries > MAX_QUERIES:
                    kill_and_log(f"TOO MANY QUERIES ({queries}) ax,ay=({ax},{ay}), sx,sy=({sx},{sy}), r={r}")
                    return -1
                _, xs, ys = line.split()
                xq, yq = int(xs), int(ys)
                if sx - r <= xq <= sx + r and sy - r <= yq <= sy + r:
                    kill_and_log(f"INVALID QUERY INSIDE EXCLUSION ({xq},{yq}) ax,ay=({ax},{ay}), sx,sy=({sx},{sy}), r={r}")
                    return -1

                dx, dy = sx - xq, sy - yq
                if dx == 0 or dy == 0 or abs(dx) == abs(dy):
                    resp = "IND"
                else:
                    if abs(dx) > abs(dy):
                        resp = "E" if dx > 0 else "O"
                    else:
                        resp = "N" if dy > 0 else "S"

                proc.stdin.write((resp + "\n").encode()); proc.stdin.flush()

            elif line.startswith('Respuesta:'):
                parts = line.split()
                if len(parts) < 3:
                    kill_and_log("MALFORMED Respuesta LINE")
                    return -1
                rx, ry = int(parts[1]), int(parts[2])
                if (rx, ry) == (sx, sy):
                    return queries
                else:
                    log.write(f"Test {test_id}: WRONG ANSWER got=({rx},{ry}) expected=({sx},{sy}) ax,ay=({ax},{ay}) queries={queries}\n")
                    return -1
            else:
                # ignore stray lines
                continue
    finally:
        try: proc.stdin.close()
        except:pass

        try: proc.stdout.close()
        except: pass
        proc.kill()
        proc.wait()

def main():
    if len(sys.argv) < 2:
        print("Usage: judge.py <solution_executable>", file=sys.stderr)
        sys.exit(1)

    sol_cmd = sys.argv[1:]
    random.seed(12345)
    queries = 0
    with open("judge_log.txt", "w") as log:
        for test_id in range(1, NUM_TESTS+1):
            result = run_test(sol_cmd, log, test_id)
            if result < 0:
                # Test failed, no need to keep going
                break
            else:
                queries += result
        print(f"Avg queries needed: {queries / NUM_TESTS}")

if __name__=="__main__":
    main()


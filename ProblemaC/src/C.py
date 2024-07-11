import math

L = 10 ** 8
Y = -4 * L

if __name__ == '__main__':
    while True:
        try:
            line = input().strip()
        except:
            break
        x, y = [int(s) for s in line.split()]
        x1 = None
        x2 = None
        # find the point for line with slope 1
        left = - 6 * L
        right = - 2 * L
        while left <= right:
            k = (left + right) // 2
            print(f'? {k} {Y}', flush = True)
            answer = input().strip().upper()
            if answer == 'IND':
                x1 = k
                break
            elif answer == 'N':
                right = k - 1
            elif answer == 'E':
                left = k + 1
            else:
                raise Exception('Unexpected answer')
        if x1 is None:
            raise Exception('Unsuccessful search')
        # find the point for line with slope -1
        left = 2 * L 
        right = 6 * L
        while left <= right:
            k = (left + right) // 2
            print(f'? {k} {Y}', flush = True)
            answer = input().strip().upper()
            if answer == 'IND':
                x2 = k
                break
            elif answer == 'N':
                left = k + 1
            elif answer == 'O':
                right = k - 1
            else:
                raise Exception('Unexpected answer')
        if x2 is None:
            raise Exception('Unsuccessful search')
        # compute the crossing point of both lines
        """
            Y =  1 * x1 + b1
            Y = -1 * x2 + b2

            b1 = Y - x1
            b2 = Y + x2

            y =  1 * x + b1
            y = -1 * x + b2

            x + b1 = -x + b2
            x = (b2 - b1) // 2
        """
        b1 = Y - x1
        b2 = Y + x2
        x = (b2 - b1) // 2
        #x = int(math.floor((b2 - b1) / 2 + 0.5))
        y = x + b1
        #print('x1', x1, 'x2', x2, 'b1', b1, 'b2', b2, 'x', x, 'y', y)
        if -x + b2 != y:
            raise Exception("Arithmetic error")
        #
        print(f'Respuesta: {x} {y}', flush = True)

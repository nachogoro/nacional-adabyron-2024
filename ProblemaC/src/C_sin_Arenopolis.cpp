#include <bits/stdc++.h>

using ll = long long;
using point_t = std::pair<ll, ll>;
constexpr ll M = 100'000'000;

constexpr ll safe_y = 3 * M;
// (x_east, safe_y) always reads "E" for any position of the singularity.
// x_east is the rightmost value which fulfils this condition.
constexpr ll x_east = -5 * M - 1;

// (x_leftmost_south, safe_y) always reads "S" for any position of the singularity.
// x_leftmost_south is the leftmost value which fulfils this condition.
constexpr ll x_leftmost_south = -M + 1;

// (x_rightmost_south, safe_y) always reads "S" for any position of the singularity.
// x_rightmost_south is the rightmost value which fulfils this condition.
constexpr ll x_rightmost_south = M - 1;

// (x_west, safe_y) always reads "W" for any position of the singularity.
// x_west is the leftmost value which fulfils this condition.
constexpr ll x_west = 5 * M + 1;

std::map<point_t, std::string> cache;

std::string ask(ll x, ll y) {
	if (cache.count({x, y})) {
		return cache.at({x, y});
	}

	std::string answer;
	std::cout << "? " << x << " " << y << std::endl;
	std::cin >> answer;

	cache[{x, y}] = answer;
	return answer;
}

point_t binaryHorizontal(
		point_t a, std::string_view a_lecture,
		point_t b, std::string_view b_lecture)
{
	ll y = a.second;

	ll low = a.first;
	ll high = b.first;

	const auto lowAnswer = a_lecture;
	const auto hiAnswer = b_lecture;

	while (low < high - 1) {
		auto mid = (low + high) / 2;
		auto answer = ask(mid, y);

		if (answer == "IND")
			return {mid, y};

		if (answer == lowAnswer) {
			low = mid;
		} else {
			high = mid;
		}
	}

	return {low + 1, y};
}

point_t exploreHorizontally() {
	auto p1 = binaryHorizontal(
			{x_east, safe_y}, "E",
			{x_leftmost_south, safe_y}, "S");

	auto p2 = binaryHorizontal(
			{x_rightmost_south, safe_y}, "S",
			{x_west, safe_y}, "O");

	auto singularityX = (p1.first + p2.first) / 2;
	auto singularityY = p1.second - (singularityX - p1.first);

	return {singularityX, singularityY};
}

int main() {
	ll x, y;

	while (std::cin >> x >> y)
	{
		cache.clear();

		auto result = exploreHorizontally();
		std::cout << "Respuesta: " << result.first << " " << result.second << std::endl;
	}
}

#include <bits/stdc++.h>

using ll = long long;
using point_t = std::pair<ll, ll>;

constexpr ll MIN = -1000000000;
constexpr ll MAX = +1000000000;

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

ll slope(point_t ind) {
	auto answerRight = ask(ind.first + 1, ind.second);

	if (answerRight == "S") return -1;
	if (answerRight == "N") return 1;

	auto answerDown = ask(ind.first, ind.second - 1);
	if (answerDown == "N") return -1;
	return 1;
}

point_t binaryHorizontal(point_t a, point_t b) {
	ll y = a.second;

	ll low = a.first;
	ll high = b.first;

	const auto lowAnswer = ask(low, y);

	if (lowAnswer == "IND")
		return {low, y};

	const auto hiAnswer = ask(high, y);
	if (hiAnswer == "IND")
		return {high, y};

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

point_t binaryVertical(point_t a, point_t b) {
	ll x = a.first;

	ll low = a.second;
	ll high = b.second;

	const auto lowAnswer = ask(x, low);

	if (lowAnswer == "IND")
		return {x, low};

	const auto hiAnswer = ask(x, high);
	if (hiAnswer == "IND")
		return {x, high};

	while (low < high - 1) {
		auto mid = (low + high) / 2;
		auto answer = ask(x, mid);

		if (answer == "IND")
			return {x, mid};

		if (answer == lowAnswer) {
			low = mid;
		} else {
			high = mid;
		}
	}

	return {x, low + 1};
}

point_t exploreHorizontally(ll x, ll y) {
	auto p1 = binaryHorizontal({MIN, y}, {x, y});
	auto p2 = binaryHorizontal({x, y}, {MAX, y});

	auto singularityX = (p1.first + p2.first) / 2;

	auto p1Slope = slope(p1);

	// y = mx + b
	auto b = p1.second - p1Slope*p1.first;
	auto singularityY = p1Slope * singularityX + b;
	return {singularityX, singularityY};
}

point_t exploreVertically(ll x, ll y) {
	auto p1 = binaryVertical({x, MIN}, {x, y});
	auto p2 = binaryVertical({x, y}, {x, MAX});

	auto singularityY = (p1.second + p2.second) / 2;

	auto p1Slope = slope(p1);

	// y = mx + b
	auto b = p1.second - p1Slope*p1.first;
	auto singularityX = (singularityY - b) / p1Slope;
	return {singularityX, singularityY};
}

int main() {
	ll x, y;

	while (std::cin >> x >> y)
	{
		cache.clear();

		std::string answer;
		while ((answer = ask(x, y)) == "IND") {
			x++;
		}

		point_t result;
		if (answer == "N" || answer == "S") {
			result = exploreHorizontally(x, y);
		} else {
			result = exploreVertically(x, y);
		}
		std::cout << "Respuesta: " << result.first << " " << result.second << std::endl;
	}
}

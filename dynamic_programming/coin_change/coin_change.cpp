// C/C++ File

// Author:   Alexandre Tea <alexandre.qtea@gmail.com>
// File:     /Users/alexandretea/Work/concepts/dynamic_programming/exercices/coin_change.cpp
// Purpose:  TODO (a one-line explanation)
// Created:  2017-06-15 11:29:13
// Modified: 2017-06-15 12:56:25

#include <iostream>
#include <vector>
#include <unordered_map>

struct pairhash {
    public:
        template <typename T, typename U>
        std::size_t operator()(const std::pair<T, U> &x) const
        {
            return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
        }
};

typedef std::unordered_map<std::pair<int, int>, unsigned int, pairhash>
CoinChangeCache;

static long long
rec_make_change(CoinChangeCache& cache,
                std::vector<int> const& coins,
                int max_idx, int money)
{
    //std::cout << "debug: " << max_idx << "  " <<  coins[max_idx] << "  " << money << std::endl;
    // base cases
    if (money == 0)
        return 1;
    else if (max_idx == 0) {
        if (coins[max_idx] == money
            or (coins[max_idx] < money and money % coins[max_idx] == 0))
            return 1;
        return 0;
    }
    else if (coins[max_idx] > money) {
        for (int i = max_idx - 1; i >= 0; --i) {
            if (money >= coins[i]) {
                return rec_make_change(cache, coins, i, money);
            }
        }
        return (money == 0 ? 1 : 0);
    }

    // check cache
    auto it = cache.find(std::make_pair(money, coins[max_idx]));
    if (it != cache.end())
        return it->second;
    int res = rec_make_change(cache, coins, max_idx - 1, money)
              + rec_make_change(cache, coins, max_idx, money - coins[max_idx]);
    cache[std::make_pair(money, coins[max_idx])] = res;
    return res;
}

static long long
make_change(std::vector<int> const& coins, int money)
{
    // pair<money, max_coin>
    CoinChangeCache   cache;

    //std::cout << "coins: ";
    //for (auto& i: coins)
        //std::cout << i;
    //std::cout << std::endl;

    return rec_make_change(cache, coins, coins.size() - 1, money);
}

int
main()
{
    int n;
    int m;

    std::cin >> n >> m;
    std::vector<int> coins(m);

    for (int coins_i = 0; coins_i < m; coins_i++) {
        std::cin >> coins[coins_i];
    }
    std::sort(coins.begin(), coins.end());
    std::cout << make_change(coins, n) << std::endl;
    return EXIT_SUCCESS;
}

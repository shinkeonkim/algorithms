#include <bits/stdc++.h>

#define MX 10000 // 최대 코인 개수를 명시합니다.
#define COST_MAX 10000 // 최대 금액을 명시합니다.

using namespace std;

int coinChange(vector <int> &coins, int money) {
  /*
    money만큼 거슬러주기 위해 필요한 최소 동전 개수를 반환합니다.
    불가능한 경우, -1을 반환합니다.
  */

  vector <int> dp(money + 1, money + 1); // dp[i] : i 라는 금액을 거슬러주기 위해 필요한 최소 동전 개수
  
  dp[0] = 0; // 0원을 거슬러 주기 위해 0개의 동전이 필요합니다.
  
  sort(coins.begin(), coins.end(), greater<int>());

  for(int coin: coins) {
    for(int i = coin; i <= money; i++) {
        dp[i] = min(dp[i], dp[i - coin] + 1);
    } 
  }
  return dp[money] <= money ? dp[money] : -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector <int> coins = {1, 4, 6};
  int money = 8;

  cout << coinChange(coins, money) << endl; // return: 2 (8 = 4 + 4)

  coins = {2};
  money = 5;

  cout << coinChange(coins, money) << endl; // return: -1

  coins = {19};
  money = 0;

  cout << coinChange(coins, money) << endl; // return: 0
}

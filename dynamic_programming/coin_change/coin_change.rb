def coin_change(coins, money)
  """
  money만큼 거슬러주기 위해 필요한 최소 동전 개수를 반환합니다.
  불가능한 경우, -1을 반환합니다.
  """

  dp = [money + 1] * (money + 1) # dp[i] : i 라는 금액을 거슬러주기 위해 필요한 최소 동전 개수
  
  dp[0] = 0 # 0원을 거슬러 주기 위해 0개의 동전이 필요합니다.
  
  coins = coins.sort.reverse

  coins.each do |coin|
    (coin..money).each do |i|
      dp[i] = [dp[i], dp[i - coin] + 1].min
    end
  end
  
  return (dp[money] <= money ? dp[money] : -1)
end

coins = [1, 4, 6]
money = 8

p coin_change(coins, money) # return: 2 (8 = 4 + 4)

coins = [2]
money = 5

p coin_change(coins, money) # return: -1

coins = [19]
money = 0

p coin_change(coins, money) # return: 0

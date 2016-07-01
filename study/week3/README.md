#cookie
```
1)
DC1 * dp[1] + 
DC2 * dp[2] + 
.....
DCn * dp[n] , where aCb denotes (a choose b.)

2)
dp[i] = sum { 1 <= j < i } dp[i-j]

Then, 1) + 2) derives :

(D/1) * dp[1] +
D * (D-1) / (2*1) * [ dp[1] ] +
D * (D-1) * (D-2) / (3*2*1) * [ dp[2] + dp[1] ] +

```

## modulo arithmetic
```
(a*b) (mod n) == (a mod n) * (b mod n)
(a+b) (mod n) == (a mod n) + (b mod n)
(a-b) (mod n) == (a mod n) - (b mod n)

!!!!
(a/b) (mod n) == (a mod n)(b^{-1} mod n)

```

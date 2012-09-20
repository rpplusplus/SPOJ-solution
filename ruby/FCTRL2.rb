a = [1, 1]
(2..100).each { |i|	a << (a[i - 1] * i)}

t = gets.to_i
(1..t).each{ |i| x = gets.to_i; puts a[x]}
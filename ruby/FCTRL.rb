t = gets.to_i
while t > 0
	t = t - 1;
	n = gets.to_i
	result = 0
	while n > 1
		result += n / 5;
		n /= 5;
	end
	puts result
end

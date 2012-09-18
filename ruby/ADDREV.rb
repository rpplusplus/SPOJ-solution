def reverse( x )
	x = x.to_i
	result = 0
	while x > 0
		result *= 10
		result += (x % 10)
		x /= 10
	end
	return result
end

t = gets
t = t.to_i
while t>0
	arr = (gets).to_s.split
	puts reverse(reverse(arr[0]) + reverse(arr[1]))
	t = t - 1
end
a = [2, 3, 5, 7, 9, 11, 13];
(14..31623).each{
	|i| 
	flag = true
	(2..Math.sqrt(i).to_i).each {
		|j| if (i % j == 0) 
				flag = false
				break
			end
	}
	if flag
		a << i
	end
}

t = gets.to_i;
(1..t).each { 
	input = gets.split;

	(input[0].to_i..input[1].to_i).each { 
		|e|  
		if (e == 1)
			next;
		end
		
		flag = true;
		a.each {
			|i|
			if (i > Math.sqrt(e)) 
				break;
			end

			if (e % i == 0)
				# puts e.to_s + ' ' + i.to_s 
				flag = false;
				break;
			end
		}
		if (flag)
			puts e;
		end
	}
	puts
}
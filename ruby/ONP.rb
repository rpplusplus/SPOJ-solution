class Node
	attr_accessor :Left, :Right, :self
end

def check( str, st, fi ) 
    for  i in st..fi
        if (str[i] == '/' || str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '^')
            return false;
        end
    end
    return true
end

def makeTree( str, st, fi)
	puts st.to_s + ' ' + fi.to_s

 	root = Node.new
	if ( check( str, st, fi) )
		if (str[st.to_i].to_s != '(')
			root.self = str[st.to_i]
		elsif 
			root.self = str[fi.to_i]
		end

		root.Left = root.Right = nil
	end

	k = 1
	minP = 2147483646
	minPos = -1

	for i in st..fi
		nowP = 2147483647
		
		if ((str[i]).to_s == '(')
			k += 3
		end

		if ((str[i]).to_s == ')')
			k -= 3
		end

		if ((str[i]).to_s == '+' || (str[i]).to_s == '-')
			minP = k
		end

		if ((str[i]).to_s == '*' || (str[i]).to_s == '/')
			minP = k + 1
		end

		if ((str[i]).to_s == '^')
			minP = k + 2
		end

		if nowP <= minP
			minP = nowP
			minPos = i
		end
	end

	root.self = str[minPos];
	root.Left = makeTree( str, st, minPos - 1);
	root.Right = makeTree( str, minPos + 1, fi);
	return root
end

def dfs( root )
	if root.Left != nil 
		dfs(root.Left);
	end

	if root.Right 
		dfs(root.Right);
	end

	print root.self;
end
	
t = gets
t = t.to_i
while (t > 0)
	str = gets
	root = makeTree(str, 0, str.length-2);
	dfs( root );
	t = t - 1;
end


import random
n = 8
if __name__=='__main__':
	f = open('sort.txt', 'r+')
	lines = f.readlines()
	lines[0] = [int(x) for x in lines[0].split()]
	lines[1] = [int(x) for x in lines[1].split()]
	n_gates, n_wires = lines[0]
	n1, n2, n3 = lines[1]
	print(lines[1])
	print(n_gates, "  ", n_wires)
	
	lines = lines[3:]

	def check_circuit(a, b):
		wire = [0 for i in range(n_wires)]
		for i in range(n1):
			wire[i] = a[i]
		print(wire[:n1])
		for i in range(n2):
			wire[i+n1] = b[i]
		print(wire[n1:n1+n2])
		
		

		# print(lines)
		for line in lines:
			line = line.split()
			for i in range(len(line)-1):
				line[i] = int(line[i])
			if line[-1] == 'XOR':
				wire[line[-2]] = wire[line[2]]^wire[line[3]]
			else:
				wire[line[-2]] = wire[line[2]]&wire[line[3]]
		r = ''
		# for i in range(n_wires):
		# 	print(" i = ",i ,"   ", wire[i])
		return(wire[-n3:])
		

	def transform_vector(A):

		x = [i for i in range(len(A)*32)]
		for i in range(len(A)):
			a_bin = bin(A[i])[2:]
			# print(a_bin)
			while len(a_bin)<32:
				a_bin = '0'+a_bin
			for j in range(32):
				x[j+i*32] = int(a_bin[j])
		return x


	def check_subtract(lines, n1, n2, n3):
		global n
		a = [i for i in range(5)]
		b = [i for i in range(5)]
		for i in range(5):
			a[i] = random.getrandbits(5)
			b[i] = random.getrandbits(5)
		for i in range(n):
			print(a[i], end='  ')
		print()
		a_vec = transform_vector(a)

		for i in range(n):
			print(b[i], end='  ')
		print()
		b_vec = transform_vector(b)
		r = check_circuit(a_vec, b_vec, lines)
		print("-----")
		for i in range(int(len(r)/32)):
			y = r[i*32:(i+1)*32]
			y = [str(i) for i in y]
			y = ''.join(y)
			print(int(y,2), end=' ')

	def test(a, b):
		print ("calculate ", a, " - ", b)
	# check_subtract(lines, n1, n2, n3)
	# global n
		a_bin = bin(a)[2:]
		b_bin = bin(b)[2:]
		while len(a_bin)<n:
			a_bin =  '0' + a_bin
		while len(b_bin)<n:
			b_bin =  '0' + b_bin
		a = [int(i) for i in a_bin]
		b = [int(i) for i in b_bin]

		r = check_circuit(a, b)
		print("result ",r, "   ")
		r = [str(i) for i in r]
		r = "".join(r)
		print("int =>  ", int(r,2))

	print("-------")
	test(30, 3) #a-b
	print("-------")
	test(20, 3) #a-b
	print("-------")
	test(31, 1) #a-b
	print("-------")
	test(31, 2) #a-b
	print("-------")
	test(31, 3) #a-b




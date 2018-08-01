def increment(i):
	print("i = " + str(i))
	increment(i + 1)

def main():
	increment(10000)

main()

#stopped after i = 10906
#tested by pycharm


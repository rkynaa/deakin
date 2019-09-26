from splashkit import *

import random

def main():
    # program entry point here...
    pass

if __name__ == "__main__":
    main()

def read_string(prompt):
  return input(prompt)
  
def read_integer(prompt):
  line = read_string(prompt)
  while not line.isdigit():
    print("Please enter a whole number")
    line = read_string(prompt)
  return int(line)
  
name = read_string("Enter name: ")
age = read_integer("Enter your age: ")

print("Hello ", name)
print("It's great to be ", age)

target = random.randrange(1,100)
print("My target is ", target)

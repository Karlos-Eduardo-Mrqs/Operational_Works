import random;
numbers = [];
for i in range(1,10):
    RandomNum = random.randint(0,15) ;
    numbers.append(RandomNum);
    Equal = bool(numbers.count(RandomNum) > 1);
    if(Equal):
        numbers.remove(RandomNum);

numbers.sort(reverse=False);
print(numbers,);
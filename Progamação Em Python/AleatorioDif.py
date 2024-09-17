import random;
nums = [];
for i in range(1,10):
    NumAleatorio = random.randint(0,15) ;
    nums.append(NumAleatorio);
    Igual = bool(nums.count(NumAleatorio) > 1);
    if(Igual):
        nums.remove(NumAleatorio);

nums.sort(reverse=False);
print(nums);
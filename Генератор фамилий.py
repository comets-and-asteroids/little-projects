import random

post = ["рик", "ов", "ев", "чук", "ный", "кий", "ко", "ли", "зе", "ян"]

sogl = ["ц", "к", "н", "г", "ш", "щ", "з", "ж", "д", "л", "р", "п", "в", "ф", "ч", "с", "м", "т", "б"]
gla = ["у", "е", "о", "а", "я", "и"]
for h in range(100):
    size = random.randint(3, 7)
    weight = 0
    surname = ""
    for i in range(size):
        key = random.randint(0, 3)
        if key + weight < 3:
            if weight < 0:
                weight = 0
            weight += 1
            if len(surname) != 0 and surname[-1] in sogl:
                temp = sogl.copy()
                temp.remove(surname[-1])
                surname += temp[random.randint(0, len(temp) - 1)]
            else:
                surname += sogl[random.randint(0, len(sogl) - 1)]
        else:
            if weight > 0:
                weight = 0
            weight -= 1
            surname += gla[random.randint(0, len(gla) - 1)]
    surname+=post[random.randint(0, len(post) - 1)]
    print(surname.capitalize())

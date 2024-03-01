import turtle


def move(a, b, vect):
    """
    :param a: Половина ширины поля
    :param b: Половина высоты поля
    :param vect: напрвление движения двумерный массив представляет
     собой расстояния по каждой из координат на
      которое необходимо подвинуть мышь
    :return: Возвращает истину после завершения работы
    """
    x = -a
    y = -b
    while True:
        turtle.goto(x + vect[0], y + vect[1])
        x += vect[0]
        y += vect[1]
        if turtle.isdown():
            turtle.up()
        else:
            turtle.down()
        if (x == a and y == b) or (x == -a and y == b) or (x == a and y == -b) or (x == -a and y == -b):
            return True
        if x == -a or x == a:
            vect[0] *= -1
        if y == b or y == -b:
            vect[1] *= -1


def square(a, b):
    """
    Данная функция рисует границы поля
    :param a: половина ширины
    :param b: половина высоты
    :return: ничего не возвращает
    """
    turtle.up()
    turtle.goto(-a,-b)
    turtle.down()
    turtle.goto(a, -b)
    turtle.goto(a, b)
    turtle.goto(-a, b)
    turtle.goto(-a, -b)


def start():
    """
    Функция запуска программы
    Данная функция выполняет стартовые приготовления для запуска программы
    Запрашивает ширину и высоту поля и вызывает функцию отрисовывающую его
    И запускает функцию движения
    :return:
    """
    a = int(input()) * 5
    b = int(input()) * 5
    turtle.setup(a, b)
    turtle.width(3)
    square(a, b)
    turtle.pen()
    move(a, b, [10, 10])
    turtle.exitonclick()


start()

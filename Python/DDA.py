import matplotlib.pylab as pl


def DDA(x1, y1, x2, y2):

    dx = abs(x2 - x1)
    dy = abs(y2 - y1)
    if(dx) > (dy):
        steps = (dx)
    else:
        steps = (dy)

    xinc = float(dx / steps)
    yinc = float(dy / steps)

    for i in range(0, int(steps + 1)):
        pl.plot(round(x1), round(y1), "m.")

        x1 = x1 + xinc
        y1 = y1 + yinc

        print('(', x1, ',', y1, ')')

    pl.title('GRAFICACIÓN')
    pl.xlabel('X')
    pl.ylabel('Y')
    pl.grid(color='k', linestyle='dotted', linewidth=1)
    pl.show()

    print("Valor dx: ", dx)
    print("Valor dy: ", dy)
    print("Valor steps: ", steps)
    print("Valor xinc: ", xinc)
    print("Valor yinc: ", yinc)


def main():
    x1 = int(input("Ingrese x1: "))
    y1 = int(input("Ingrese y1: "))
    x2 = int(input("Ingrese x2: "))
    y2 = int(input("Ingrese y2: "))

    DDA(x1, y1, x2, y2)


if __name__ == "__main__":
    main()

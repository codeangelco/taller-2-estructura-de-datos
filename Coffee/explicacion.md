# [Coffee](https://www.hackerrank.com/contests/utp-open-2018/challenges/cup-of-coffee/problem)

Se nos pide hayar la altura con la cual llenamos la mitad de una taza de cafe.

Utilizamos metodo de bisección, ya que tenemos que iterar con varios valores de h en una funcion: $F(h) =\frac{1}{3} * \pi* h * (r^2 + R^2 + R * r)$

### A tener en cuenta:
El valor de R cambia segun la altura, así que se piensa en triangulos semejantes y que si:
$$
\frac{R'-r}{h'} = \frac{R-r}{h}
$$
Entonces para iterar en la formula inicial, simplemente despejamos la anterior para obtener R':
$$
R'=r+\frac{R-r}{h}*h'
$$

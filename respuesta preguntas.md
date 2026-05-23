1) Parallelize this loop using OpenMP.Ar ethere any data dependencies or shared variables?
  El loop se pudo paralelizar usando OpenMP sin problema, ya que no existen dependencias de datos entre iteraciones, cada iteracion escribe una posicion distinta de X. Las variables compartidas son X y N.
  
Loop paralelizado:
    #pragma omp parallel for schedule(dynamic, 1)
    for (unsigned int k = 0; k < N; k++) {
        X[k] = Riemann_Zeta(2.0, k);
    }
2) Elaborate on the load balancing of the individual threads.
La funcion Riemman_Zeta(s,k) contiene dos loops, por lo que depende de k^2, lo que implica que para valores muy grandes de k, se necesita mucho mas tiempo que para valores pequeños. Se utiliza schedule(dynamic,1) para balancear.
3) Discuss different scheduling modes and the corresponding runtimes. 
Con "Static" las iteraciones se distribuyen en bloques fijos, lo que puede causar un mal balance de la carga.
Con "Dynamic" las iteraciones se asignan dinamicamente, lo que quiere decir que cuando un thread termina una iteracion, recibe inmediatamente la siguiente.
Con "Guided" empieza con bloques grandes y luego bloques cada vez mas pequeños,
Para este problema metodos como dynamic y guided son mas apropiados, ya que es proporcional a k^2, y estos metodos reducen el costo computacional.

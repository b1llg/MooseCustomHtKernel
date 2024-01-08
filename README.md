Moose Custom Heat Transfer Kernel
=====

Custom heat transfer kernel to solve the heat equation [^1]:
[^1] A first course in finite elements, T. Belytshko, J. Fish. equation (6.31)

$$\int_{\Omega} (\nabla w)^{T}\cdot k \nabla \theta \; d \Omega + \int_{\Gamma_{q}}w \bar q \; d\Gamma - \int_{\Omega}w s \;d \Omega = 0$$

in inner product notation:
$$\underbrace{(\nabla w, k \nabla \theta)}_\text{main kernel} - \underbrace{(w,s)}_\text{Heat generation} + \underbrace{(w,\bar q\cdot\vec{n} )}_\text{Flux boudnary condition} = 0 $$


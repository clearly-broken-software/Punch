RMS(size) = power_of_two : integrate(size) : sqrt
 with {
	power_of_two(x) = x * x;
	integrate(size,x) = delaysum(size, x)/size;
    
    delaysum(size) = _ <: par(i,rmsMaxSize, @(i)*(i<size)) :> _;
	//delaysum(size,x) = x@(size-1) + 
	//	select2(size > 0, 0, delaysum(size-1, x));
 };

/*RMS(n) = os.square : mean(n) : sqrt */
/*with {*/
	/*mean(n,x) = x - x @ n : + ~ _ : /(n);*/
	/*os.square(x) = x * x;*/
/*};*/

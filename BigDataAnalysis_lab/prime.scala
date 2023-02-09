def isPrime(i :Int) : Boolean = {
    if (i <= 1)
        false
    else if (i == 2)
        true
    else
        !(2 to (i-1)).exists(x => i % x == 0)
}

var data = 0
for( w <- 0 to 1000)
if (isPrime(w))
  data += w
println(data)
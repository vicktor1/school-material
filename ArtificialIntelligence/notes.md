# First Day
---
1. 15 experiment   
2. Final Project
	- term paper
	- project
3. Discussion on AI and Machine Learning

AI lab 1

[school link](https://www.ics.uci.edu/~dechter/courses/ics-275a/fall-99/slides/node280.html)


# A* algorithm
```
Default value of g for every node is infinite 
g(start) <- 0
Parent(start) <- null
f(start) <- g(start)th (start)
open <- {start}
close <- {}

while open is not empty
	Remove node N with lowest value from open 
	close <- close U { N }
	IF GoalTest(N) = true
		return success
	else
		for all childs M belongs MoveGen(N)
			IF (g(N) + k(M, N) < g(M))
			{
				Parent(M) <- N
				g(M) = g(N) + k(M, N)
				f(M) = g(M) + h(M)
				IF M in open continue
				ELSE IF M in close { Propogate Improvement(M) }
				ELSE add M to open (New Node)
			}
return FAILURE


PropogateImprovement(M)
{
	for each child X in MoveGen(M)
	IF (g(M) + k(M, X) < g(X))
	{
		Parent(X) <- M
		g(X) = g(M) + k(M, X)
		f(X) = g(X) + h(X)
		IF X in close
			propogateImprovement(X)
	}
}



```

game of kids

```
    -----
    | A |
    -----
    | B |
    -----     -----
    | C |     | E |
    -----     -----
    | D |     | F |
----------------------

    -----
    | A |
    -----
    | E |
    -----
    | B |
    -----     
    | C |     
    -----     -----
    | D |     | F |
----------------------
```
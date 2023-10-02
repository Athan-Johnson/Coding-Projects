This is my A* implementation. This runs on a magaminx, (here's the wiki as you probably don't know what it is https://en.wikipedia.org/wiki/Megaminx) and all the code you see here is my own.

This project is one of my favorites. I began with a different implementation of the megaminx model, however after many hours attempting to debug it I was just seeing no results. After spending several hours trying to unsuccessfully debug the code, I learned about weak pointers and realized that with them I could rebuild this project.

I threw out almost all my code and started again, and built a fully functioning model of the megaminx. This model is especially useful as it has its own copy constructor, which makes a huge difference once I get to implementing A*.

The A* code itself is relatively simple, which had been my long term view when creating my dodecahedron object. The weakest part is my heuristic, which I could do better on but that wasn't the focus of my project. The stateNode class does most of the work for A*, again, just as I wanted when designing it.

If I ever get the free time I mean to make a few updates, one of which is already underway. My computer isn't able to computer A* beyond seven scrambles of the megaminx, and this is because my ram caps out. In order to fix this I started implementing an "advancedNode", which isn't really "advanced" but instead records the rotations performed to get here instead of an entire dodecahedron object, but this will require recalculating all the rotations. Essentially, this idea saves space but requires more CPU power.

To augment this I would also like to implement multithreading, as that would help to offset the increased CPU cost.

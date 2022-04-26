# Project 10: 42_containers

## Implementing map, vector and stack, containers available in C++ STL
</br>

[![opacaud's 42 ft_containers Score](https://badge42.vercel.app/api/v2/cl2g6sk3a013609l6l237136q/project/2487499)](https://github.com/JaeSeoKim/badge42)
</br>
</br>

I designed my Makefile so that it launches the compilation of two different executables.
* One, called ft_container_mine, using the main function in the main_mine.cpp file.
* The other, called ft_containers_real, using the main function in the main_real.cpp file.
</br>

The point is to prove that my ft::map, ft::vector and ft::stack replicate the behaviors of std::map, std::vector and std::stack.
</br>
</br>

Run ```make```
</br>
Run ```./ft_containers_mine > mine```
</br>
Run ```./ft_containers_real > real```
</br>
Run ```diff mine real```
</br>
</br>

The differences you will see appear are precisely only the differences of the containers I called in one main and in the other.
When ft::vector is called in main_mine, std::vector is called in main_real, for instance.
</br>

You may open the main files and actually run ```./ft_containers_mine``` to compare the tests I ran and their output.
</br>

Do so at your own peril though. I ran a loooooot of tests to make sure my containers were not faulty.
</br>

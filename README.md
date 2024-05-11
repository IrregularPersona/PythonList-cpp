# About API:
------
This is an api recreation of Python's list inside of C++, without using external dependencies (vanilla C++). The container itself is a vector that can hold int, C++'s string object, boolean, and doubles. I've tried my best to recreate the following methods:

1. append
2. clear
3. copy
4. count
5. extend
6. index
7. pop
8. remove
9. reverse
10. sort

You can directly compile it with the cpp file itself instead of the obj file. In the given sample, for the sake if simplicity, I used an obj file, because its easier to work with.

## Building:
 ----------
Minimum C++ standard version is C++17. 
Use the available makefile. You can modify it to work in your own custom workspace.

----

### About me and the Project:

- Reasoning:
    This project was started out of my own curiousity of whether a type-ambiguous list can be implemented in C and C++. It is kinda stupid why anyone would wanna do this, but if it seems dumb, then for me, I'd just do it. I haven't seen any implementation of this on github, except for [the one](https://github.com/pri22296/pyList) that implements it with one specific type only, and the creator seems to only give implementations for int's, and not chars or other types (not that I have tried it personally).

- C:

     I reached a quite the roadblock when doing it in C, because of the lack of type safety and just my lack of understanding how memory works (I am after all a first-year student). 

- C++:

    When I looked into C++, I first stumbled upon a StackOverflow [article](https://google.com) that answered my question (albeit from 2009(?)). The only problem with the page was that the answers kept recommending the usage of Boost.any, which is an external dependency. What I wanted to do was implement this entire thing on vanilla C/C++ wherever I can. And, thats when I found std::variant from the C++17 standard.

- std::variant:

    When I first looked into std::variant, I instantly knew it was the perfect thing to use for my case here. It was essentially a type-safe union, and it was similar enough to my first C implementation. I set the types as only ints, std::string's, doubles and bools. This is purely as a first time thing, as this is my first dedicated project in regards to C++. 
    
    
- Limitations:
    Looking back, it has some limitations where because I specified the types in the .hpp file, it can't really store anything other than the specified types. I'll return to this project someday and replace std::variant with std::any.



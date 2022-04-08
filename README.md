<div id="top"></div>

<br />
<div align="center">

  <h3 align="center">Library Management System in C++</h3>

  <p align="center">
    Library management implemented in C++ using Object Oriented Programming
    <br />
    <a href="https://github.com/Deepak-Sangle/Library-Management-System-in-C-"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Deepak-Sangle/Library-Management-System-in-C-">View Demo</a>
    ·
    <a href="https://github.com/Deepak-Sangle/Library-Management-System-in-C-/issues">Report Bug</a>
    ·
    <a href="https://github.com/Deepak-Sangle/Library-Management-System-in-C-/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
      </ul>
    </li>
    <li><a href="#assumptions">Assumptions</a></li>
    <li><a href="#implementation">Implementations</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][product-screenshot]](https://example.com)

I have implemented a Library Management System, completely in C++ using Object Oriented Programming for my CS253A Course Assignment.
Salient Features:
* There are basically three types of users viz. Students, Professor and Librarian.
* User can login / Logout using their credentials.
* There are different functionality provided to different subclass of users.
* Student and professor can see all the books, issue any book for maximum certain period of time exceeding which will penalize the user with a fixed fine, check availability of any book, see their fine amount and clear fine amount.
* Librarian can add, update, delete any user or book, can list down all the user and books, can see to all the books issued by a particular user and also see who issued a particular book.

### Built With

The Library Management is completely build using C++ Programming Language. One extra header file which is used here is 
* [time.h](https://www.geeksforgeeks.org/time-h-header-file-in-c-with-examples/)

<!-- GETTING STARTED -->
## Getting Started

You can simply open the complete project in Visual studio code editor. However, make sure that you open the csv files only using vs code and not any other software like MS Excel since the file could not be edited if you open the csv files. However you can open this csv files in the vs code editor. 

### Prerequisites

There are no such prerequistes for this project to start.

## Assumptions

There are many assumption made during the implementation of the library management. Make sure you follow those assumption.

* You cannot type multiword inputs. If you want, please use '_' to separate different words. 
  
  for eg. instead of writing Deepak Sangle, you are requested to give input as Deepak_Sangle.

* Avoid giving irrevlant input to the command line and please follow the instruction carefully as displayed on the terminal.


## Implementation

This brifely describes how you can run the code and use the Library management.

* First type the following command in the terminal 

  ```sh
  g++ main.cpp
  ```
  followed by the following command

  ```sh
    .\a.exe
  ```
* Now you are asked to Login as Student or as Professor or as Librarian. After entering correct details you will be redirected to homepage.
* In the Homepage all the commands will be displayed which the particular user can perform. After entering the suitable command you are requested to follow the steps as directed by the programme. 
* Make sure that you enter relevant details whenver asked. 
* Try exploring the programme to know everything in more detail.


# CS-300: Data Structures and Algorithms: Analysis & Design

## Academic Advising Assistance Program – Portfolio Submission

This repository contains my final portfolio artifacts for CS-300: Data Structures and Algorithms: Analysis & Design. The two pieces here represent both the analytical and practical sides of building efficient, maintainable software. The first piece is my analysis of how different data structures perform in terms of speed and memory. The second is a C++ program I built that lets academic advisors easily load, sort, and look up course information for students. Together, these show how I approach problem-solving, by evaluating my options, making design choices, and building real, efficient solutions using data structures and algorithms.

📄 [View Runtime & Memory Analysis (PDF)](Runtime_Analysis.pdf)  
💻 [View C++ Course Planner Source Code (`ProjectTwo.cpp`)](ProjectTwo.cpp)

# Reflection

Something I took away from this project is how much the data structure I chose impacted the rest of my work. It impacted everything about the program, how efficiently it ran, how functional it was, and even how I set things up in the code. I looked at vectors, hash tables, and binary search trees from the very start. I ultimately went with a hash table because I realized that advisors would want to look things up quickly, and it just makes the most sense for what they will be using it for.

The transition from analysis and pseudocode into code in C++ had its own challenges. Successfully reading from files, ensuring input was user feedback friendly, and always printing the course listing in the right order took more trial and error than anticipated. I spent many tests and rewrites getting things to the point where they were just right. I also attempted to write my code as clearly as possible for me at the time, and anyone else that may read it later. I found good variable names and lots of comments helpful. When confronting problems, I tried to break the problems down into smaller parts and walked through my logic in a stepwise manner. This approach helped me realize how everything fit together, and helped immensely with rewriting.

I am more deliberate now about striking the balance between efficiency and clarity. I thought a lot about how a third party would use the design of the program ensuring it didn't just crash or provide the user with a random runtime error message. Writing out the runtime analysis ahead of time helped me select the most appropriate data structure for the problem, rather than simply defaulting to the one I’m most comfortable with.

In conclusion, I learned to appreciate the value in having the plan before taking on something complex. The two projects taught me the importance of routing those thoughts and designs before continuing into the code. I also try to write my programs in a way that will allow for modification later. For example, I may want to expand the details of the courses allowing for additional 'information', or I may want to change the menu.

I want to continue good habits moving forward; designing for performance, documenting the process, and thinking about who are going to use that I build. 

In the end, I want my work to work well and make life easier for whoever is using it.

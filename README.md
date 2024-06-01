# General specification:
The team is hired by the restaurant to implement the restaurant management system
The system needs to store ingredients, dishes and customer information
Be able to calculate the total cost and gross profit of a customer order
Specific functions include browsing, adding, modifying, and deleting information
Users are divided into manager, Chef, and customer, each with different permissions
# Customer specification:
Store ingredients, dishes and customer information
Calculate the total cost and gross margin of a customer's order
Provide different permissions for different types of users
# System specification:
## Type: Restaurant management system
## Language: C++
## Function: 
storage, processing raw materials, dishes, customer information; Calculate total expenses and gross profit; Authority management
## Development process: 
Requirements analysis -> Outline Design -> Detailed Design -> Coding -> Testing -> Deployment
Key technologies: data storage (file or database), user rights management, algorithm design (calculation cost, gross profit)
## Development key points: 
Follow the requirements of customer specifications, the functional modules work together, and test covers all functional points
Project management: Develop schedule, communicate and feedback in time to ensure project delivery on time.
# Problem description:
A memory leak is when a program dynamically allocates memory without properly freeing it, making it unavailable and unable to be reclaimed. A memory leak in a long-running program can lead to an increase in memory usage, resulting in degraded system performance or program crashes.
## Consequences:
Memory leaks can cause a gradual decrease in available memory, especially in long-running applications that repeatedly perform allocation operations without releasing it. Eventually, these resources are exhausted, causing the operating system or program to crash, affecting the user experience.
## Solution:
To fix memory leaks, whenever memory is dynamically allocated via new or similar methods, make sure to use delete to free memory at the right time. A better approach is to use smart Pointers provided by the C++ standard library, such as std::unique and std::shared, to automatically manage the life cycle of memory.
Source code and lifecycle management through software tools (C++ systems)
# Project management tools
Tools: GitHub, 
Create a project: Create a new project repository on the platform.
Use Kanban tools such as GitHub Projects, and GitHab Issues, manage tasks and schedules.
In GitHub link is   https://github.com/hengxuanzhang/cptsolution
## Build and Continuous Integration/Continuous Deployment (CI/CD)
Tools: CMake (Build tool), GitHub Actions (CI/CD) and ninja
CMake configuration: Create the CMakeLists.txt file that defines the project and build parameters.
## Configure CI/CD:
Making Actions: create a lot/workflows/build yml configuration file, define the build, test, and deployment process.

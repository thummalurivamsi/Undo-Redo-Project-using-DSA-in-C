<img width="1920" height="1080" alt="4" src="https://github.com/user-attachments/assets/677857c1-9443-4b5e-93cf-bb5b5448881b" />🎯 Undo-Redo System in C

This project is a terminal-based Undo-Redo System developed in the C programming language using Data Structures & Algorithms (DSA). It provides efficient undo and redo operations for text editing or command-based applications, demonstrating practical use of stacks, linked lists, and file handling. This project lays a strong foundation for implementing advanced editors, version control systems, and command history managers.

📌 Project Overview

Traditional text or command editing often requires tracking changes manually, which becomes cumbersome as complexity grows. The Undo-Redo System addresses this by maintaining two dynamic stacks: one for undo operations and another for redo operations.

This allows users to revert previous actions or reapply undone actions efficiently, ensuring a seamless editing experience. The system supports multiple consecutive undo/redo operations and preserves data integrity throughout the process.

⚙️ Components / Tools Used

C Programming Language

GCC Compiler

Command-line Interface (CLI)

Stacks (for undo and redo operations)

Linked Lists (for managing action history)

Modular Programming Techniques

File Handling (for persistent storage)

📁 File Modules

main.c – Program entry point; handles user input and orchestrates undo-redo operations

undo_redo.c – Core logic for managing undo and redo stacks

stack.c – Implements add, remove, edit, and display actions

undo_redo.c – operations happens here

validate.c – Ensures input correctness and prevents invalid operations

undo_redo.h – All function declarations

🧠 Working Principle

Tracks each action (insert, delete, modify) as a node in a stack-based linked list.

Undo Stack stores the most recent actions to allow rollback.

Redo Stack stores undone actions to allow reapplication.

Supports operations such as:

Performing an action and adding it to the undo stack

Undoing the most recent action

Redoing an undone action

Ensures fast retrieval of previous states and accurate history management.

🔐 Input Validation & Error Handling

Validates commands and inputs before processing.

Prevents undoing or redoing when the respective stack is empty.

Handles invalid or empty input gracefully.

Properly allocates and deallocates memory to avoid leaks.

💡 Features

✅ Efficient undo and redo functionality
✅ Supports multiple consecutive operations
✅ Maintains integrity of action history
✅ Modular codebase for easy maintenance and extension
✅ Demonstrates dynamic memory management, stacks, and linked lists
✅ Can be extended for text editors, CLI tools, or version control systems

📂 File Structure
undo-redo-system/

├── main.c              # Program entry point

├── undo_redo.c         # Core undo-redo logic

├── undo_redo.c         # Action handling functions

├── validate.c          # Input validation

├── undo_redo.h         # Function declarations

├── README.md           # Project documentation

📸 Project Media

Project demo 👉 : https://drive.google.com/file/d/19Zhepze_O0p3Zb54q5cvN1IHWEo6PDca/view?usp=sharing

🖼️ Sample Terminal Output:

<img width="1920" height="1080" alt="1" src="https://github.com/user-attachments/assets/daf862b5-e4a2-4160-8529-a27a8564483a" />
<img width="1920" height="1080" alt="2" src="https://github.com/user-attachments/assets/74025de2-09d3-4dba-b8a9-93c672539d75" />
<img width="1920" height="1080" alt="3" src="https://github.com/user-attachments/assets/643a2002-1e94-4458-be51-386bebbc0137" />
<img width="1920" height="1080" alt="4" src="https://github.com/user-attachments/assets/2ebc0c4f-7266-4885-ad53-eab3e756f55b" />
<img width="1920" height="1080" alt="5" src="https://github.com/user-attachments/assets/e667f54d-bb4d-4dc9-a3e7-2007a24289e9" />
<img width="1920" height="1080" alt="6" src="https://github.com/user-attachments/assets/e1b18e02-4a85-4c94-abea-cae2479fb34b" />


1. Add Action
2. Undo
3. Redo
4. Display History
Enter your choice:

📈 Future Improvements

Support for multi-level undo/redo with snapshots of entire data

Integration with text file editing for full document tracking

GUI-based version for better visualization

Export action history in JSON/CSV format

Persistent storage to maintain history across sessions

Optimization using circular stacks or dynamic resizing

👨‍💻 Developed By

Anju – Embedded Systems & Data Structures Enthusiast
✉️ vamsithummaluri@gmail.com

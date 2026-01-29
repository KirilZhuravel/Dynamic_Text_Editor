📝 Dynamic Text Editor (C)
A lightweight, terminal-based text editor written in C that utilizes dynamic memory management to handle strings of arbitrary length. This project demonstrates efficient use of pointers, memory reallocation, and file I/O.

✨ Features
Dynamic Storage: Uses realloc to expand or contract memory based on user input, ensuring no wasted space.

Append Mode: Add new strings to the end of the existing buffer.

Smart Update: Modify the text at a specific "cut point," with four different logic cases:

Appending to the end.

Perfect replacement of a suffix.

Extending the buffer from a midpoint.

Truncating and replacing internal text.

Efficient Deletion: Truncate text from a specific point and shrink the memory footprint.

File Persistence: Save your current workspace buffer directly to a .txt file.

🛠 Technical Highlights
Memory Safety: Implements manual memory management with free() to prevent memory leaks.

Pointer-to-Pointer Logic: Uses char** (double pointers) to modify the base address of the string buffer within sub-functions.

Case-Based Logic: Detailed conditional handling for string manipulation (Case 1-4 in UpdateText).

🎮 Usage Guide
The program operates via a numbered menu:

Add: Input the length followed by the string to append.

Update: Specify a cut point (index) and new text. The editor handles the resizing automatically.

Del: Enter a cut point to remove all characters following that index.

Print: View the current state of the buffer.

Save: Enter a filename (e.g., notes.txt) to write the buffer to disk.

📂 Project Structure
main.c: Handles the UI loop and menu navigation.

functions.c: Core logic for memory reallocation and string operations.

functions.h: Function prototypes and header guards.

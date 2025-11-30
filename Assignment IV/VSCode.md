# Connect to GitHub with VSCode

**Development Environment:**
- **OS:** Windows 10/11
- **Editor:** Visual Studio Code
- **Terminal:** PowerShell
- **Git:** Git for Windows

## Prerequisites
Before beginning the assignment, I ensured I had the following:
- Visual Studio Code installed.
- Git installed and configured on my system (`git config --global user.name` and `user.email`).
- A GitHub account.

## Steps I Took to Connect to GitHub

1. **Install the GitHub Extension**
   - I opened VSCode and went to the **Extensions** view.
   - I searched for and installed **"GitHub Pull Requests and Issues"** to integrate Git features directly into the editor.

2. **Sign in to GitHub**
   - I clicked the **Accounts** icon (bottom left) and selected **Sign in with GitHub**.
   - I followed the browser prompts to authorize VSCode.

3. **Clone the Repository**
   - I opened the Command Palette (`Ctrl+Shift+P`) and typed `Git: Clone`.
   - I pasted the assignment repository URL.
   - I selected a local folder on my Windows machine to store the project.

4. **Open the Repository**
   - Once cloned, I opened the folder in VSCode to view the `C` and `CXX` directories.

5. **Make Changes and Commit**
   - After editing `hash_fn.c` and `hash_fn.cpp`, I used the **Source Control** view.
   - I clicked the `+` button to stage files.
   - I entered a descriptive commit message (e.g., "Optimize hash function") and clicked **Commit**.

6. **Push Changes to GitHub**
   - I clicked the **Sync Changes** button to push my code to the remote repository.

## My Experience on Windows
- **Using Makefile.bat:** Since I am on Windows, I learned that I cannot use the standard `make` command. Instead, I used the integrated terminal (PowerShell) to run:
  ```powershell
  .\Makefile.bat all
  ```
This script successfully compiled both C and C++ versions of my assignment.

- Path Separators: I noticed that Windows uses backslashes (`\`) for file paths in the terminal, unlike Linux which uses forward slashes (`/`).

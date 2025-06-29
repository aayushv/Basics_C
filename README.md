# Basics_C
C++ Basics Code  Snippet


GitHub basics


git config --global user.name "<username>"
git config --global user.email "<email-id>"
git config --list


Clone & Status

Clone - Cloning a repository on our local machine.
  git clone <-some_link->
Status - display the state of code
  git status

add - adds new or changes files in your working directory to the Git staging area.
    git add <file name>

commit - It is the record of change.
   git commit -m "some message"

push - upload local repo content to remote repo
  git push origin master

Init Command

init - used to create a new git repo

git init 

git remote add origin <-linl->

git remote -v (to verify remote)

git branch (to check branch)

git branch -M main (to rename branch)

git push origin main


Branch Commands

git branch [to check branch]

git branch -M main [to rename branch]

git checkout <branch name> [to navigate]

git checkout -b <new branch name> [to create new branch]

git branch -d <branch name> [to delete branch]

Merging Code

Way 1 

git diff <branch name> [to compare commits, branches, files and more]

git merge <branch name> [to merge 2 branches]


Way 2


Create a PR

Pull Command

git pull origin main 

used to featch and download content from a remote repo and immediately update the local repo to match that content.
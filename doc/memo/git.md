# JW Studio

Some useful information about this library

## Some usefull batch

1. Deploy Qt application

    ```batch
    "C:\Qt\Qt5.12.0\5.12.0\msvc2017_64\bin\windeployqt.exe" "application.exe"
    ```

## Some git command

1. Strip a commit
    >Reset the current branch's work space to the node which hash code is 'node_hash_code'.

    ```git
    git reset --hard [node_hash_code]
    ```

1. Clean up the workspace

    ```git
    git clean -dfx
    ```

1. Compress the history

    ```git
    git rebase -i HEAD~[node_count]
    ```

    > edit in the editor. Set the first node as "pick" while the others as "fixup". Then close the editor and on.

    ```git
    git rebase continue
    ```

## The CPlusPlus standard 14 symbol list

<https://en.cppreference.com/w/cpp/symbol_index>

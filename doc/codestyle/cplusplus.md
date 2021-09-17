# CPlusPlus Code Style

## Name Rule

Name should be descriptive, and avoid abbreviation.

1. filename
    > Mostly, the FileName should be same as the ClassName. But, all the letters should be lowercase. By also, all the source file path, include the directory name should be lowercase too. The names could be with hyphen, but not underscores.

    - header.h
    - source.cpp
    - project/inc/header.h
    - resource/icon.png
    - name-rule.md

1. TypeName
    > Type name start with a capital letter and have a capital letter for each new word, with no underscores.

    ``` C++
    class MyClass;
    enum MyEnum;
    using FuctionTable = std::map<std::string, Func*>;
    ```

1. variable_name

    1. Common Variable
        > The variables names are all lowercase, with underscores between words.

        ```C++
        void func(int number = 0, long letter_size);
        std::string helloworld = "hello world!";
        ```

    2. const Variable
        > These variables start with a leading "k" and have a capital letter for each new word. And also could be with underscores between number letters.

        ```C++
        static const kPhysicalProcessorCount = 8;
        const kListSize = 10;
        const kOpenGL3_0_0 = 0x300;
        ```

    3. Struct data members
        > The data members of structs are named like the ordinary variables, no matter whether the variables is static, no static, const or a pointer.

        ```C++
        struct MyStruct
        {
            int x;
            int y;
            int width;
            int height;
            static std::string window_title;
            MyStruct *parent;
        }
        ```

    4. Class data members
        > The data members of class are start with "_", the other rules are same as the ordinary variables.

        ```C++
        class MyClass
        {
        private:
            std::string _window_title;
            static std::map<std::string, MyClass*> *_table;
        }
        ```

1. functionName
    > The function name's first letter is lowercase, and have a capital letter for each new word.

    ```C++
    void addTable(Table *table);
    void setNewName(const Name &name);
    ```

1. namespacename
    > namespace names start with a capital letter and have a capital letter for each new word. Generally, the top-level namespace should be the solution name or the project name  (could be an abbreviation).

    ```C++
    namespace Dc
    {
        namespace TemplateLibs
        {
        }
    }
    ```

1. MACRO_NAME
    > They should be all named with Capitals and underscores.

    ``` C++
    #define MY_MACRO nullptr
    #define MACRO(name) ##name
    ```

1. EnumName
    > Enumerators name start with a capital letter and have a capital letter for each new word, with underscores between words.

    ```C++
    enum MyEnum
    {
        AA_Name1 = 0x01,
        AA_Type2 = 0x02,
    }
    ```

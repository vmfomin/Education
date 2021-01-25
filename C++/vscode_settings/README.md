# Настройка VS Code для отладки из CMake, а не из расширения C/C++

## Настройка launch.json

1. Открыть в папке .vscode файл launch.json

2. Найти строчку  

   ~~~json
   "program": "something command",
   ~~~

   и заменить команду на

   ~~~json
   "program": "${command:cmake.launchTargetPath}",
   ~~~

3. Для удобства отладки сделать истинным поле,

   ~~~ json
   "externalConsole": true,
   ~~~

   чтобы запуск отладки был в отдельном терминале, а не в Debug Console.  
   В Debug Console нельзя вводить данные с клавиатуры.

## Настройка tasks.json

1. Открыть в папке .vscode файл tasks.json

2. В строке

   ~~~json
      "args": [
        "-g",
        "${file}",
        "-o",
        "${fileDirname}\\${fileBasenameNoExtension}.exe"
      ],
   ~~~

заменить на

   ~~~json
      "-g",
      "${workspaceFolder}/*.cpp",
   ~~~

   В таком случае, отладчик будет знать, какие файлы еще брать во время компиляции.

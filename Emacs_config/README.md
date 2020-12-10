# Рекомендации по настройки emacs.
## Для Windows:
   Скопировать файл .emacs в папку C:\Users\username\AppData\Roaming

## Для Unix:
   .emacs в домашнюю директорию: /home/%username%/

  1. Выполнить package-refresh-contents.
  2. Выполнить list-package.
  3. Найти через поиск auto-complete (auto completion for GNU Emacs) и
  установить. Установка выполняется так: надо поставить курсор в самом левом
  краю от имени. Нажать i, затем x. Согласится с установкой. При нажатии i
  курсор съедет вниз, но не страшно.
  4. Установить yasnippet.
  5. Установить yasnippet-snippets.
  6. Установить auto-complete-c-headers (An auto-complete for C/C++ header
  files). Выполнить команду в shell (вызвать alt-shift-!): gcc -xc++ -E -v -
  7. В файле .emacs найти комментарий
  ;; let's define a function which initializes auto-complete-c-headers and gets
  called for c/c++ hooks.
  В нем изменить строчку (add-to-list 'achead:include-directories ' на текст за этой
  строкой #include <...> search starts here.
  Например, "C:/cygwin64/lib/gcc/x86_64-pc-cygwin/10/include". По умолчанию
  команда шелла выводит такой путь: /usr/lib/gcc/x86_64-pc-cygwin/10/include,
  но для Windows он не подойдет. Поэтому надо указать через C:/...
  

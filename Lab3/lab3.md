### Подготовка

Изучите команды `find`, `xargs`, и `grep` с помощью команды `man`.

### Задания

Используя команду `find`:

Найдите все файлы и каталоги, имя которых содержит слово `pass`, поиск начните с корневого каталога.

```sh
find / -name "*pass*"
```

Найдите все файлы и каталоги, имя которых содержит слово `pass` без учёта регистра, поиск начните с корневого каталога.

```sh
find / -iname "*pass*"
```

Найдите все файлы и каталоги, имя которых содержит слово `pass`, ограничив глубину поиска одним каталогом, поиск начните с корневого каталога.

```sh
find / -maxdepth 1 -name "*pass*"
```

Найдите все файлы и каталоги, имена которых оканчиваются на `.bin`. Поиск необходимо выполнить в каталоге `/home`.

```sh
find /home -name "*.bin"
```

Найдите все **файлы** (и только файлы) с расширением `bak` и удалите их.

```sh
find / -type f -name "*.bak" -delete
```

Найдите все **файлы** (и только файлы) с расширениями `txt` и `sh`.

```sh
find / -type f -name "*.sh" -o -name "*.txt"
```

Найдите все **файлы** (и только файлы) в текущем каталоге и выведите **только** имя файла (без каталога), владельца, группу владельца, количество жёстких ссылок на этот файл и его размер в байтах.

```sh
find . -maxdepth 1 -type f -printf "%f %u %g %n %s\n"
```

Найдите все пустые **каталоги** в текущем каталоге.

```sh
find . -maxdepth 1 -type d -empty
```

Найдите все пустые **каталоги** в текущем каталоге и удалите их.

```sh
find . -maxdepth 1 -type d -empty -delete
```

Найдите и удалите все пустые **файлы** (и только файлы).

```sh
find / -type f -empty -delete
```

Найдите все **файлы** (и только файлы) в текущем каталоге, на которые есть хотя бы одна жёсткая ссылка.

```sh
find . -maxdepth 1 -type f -links 1 -o -links +1
```

Найдите файлы и каталоги в каталоге `/etc`, **не** принадлежащие пользователю `root`.

```sh
find /etc -type f -o -type d -not -user root
```

Найдите все **файлы** (и только файлы), у которых **нет** расширения `sh`.

```sh
find / -type f -not -name "*.sh"
```

Найдите все **файлы** (и только файлы), у которых количество жёстких ссылок более двух.

```sh
find / -type f -links +2
```

Найдите все **файлы** (и только файлы) в каталоге `/usr/bin`, последний доступ к которым осуществлялся более трёх месяцев назад.

```sh
find /usr/bin -type f -atime +92
```

Найдите все **файлы** (и только файлы) в каталогах `/usr/bin` и `/usr/share`, созданные или изменённые в течении последних 10 дней.

```sh
/usr/bin /usr/share -type f -mtime -10
```

Найдите и удалите все **файлы** (и только файлы) в каталоге `/tmp`, которые не менялись более двух недель.

```sh
find /tmp -type f -mtime -14 -delete
```

Найдите все **файлы** (и только файлы) в каталоге `/usr/bin` с установленным флагом suid/sgid.

```sh
find /usr/bin -type f -perm /u+s,g+s
```

Используя команды `find` и `xargs` или параметр `-exec` команды `find`:

Найдите все **файлы** (и только файлы) с расширением `txt` и подсчитайте количество строк во всех этих файлах.

```sh
find / -type f -name "*.txt" -exec cat {} \; | wc -l
```

Найдите все каталоги с названием `.svn` и удалите их, включая содержимое этих каталогов, попутно выводя список удалённых файлов на экран.

```sh
find / -type d -name ".svn" -exec rm -rfv {} \;
```

Найдите все **файлы** (и только файлы) с расширением `sh` и добавьтем им право на исполнение.

```sh
find / -type f -name "*.sh" -exec chmod +x {} \;
```

Найдите все **файлы** (и только файлы) с расширением `conf` в каталоге `/etc` и подсчитайте их суммарный размер, используя команду du.

```sh
find /etc -type f -name "*.conf" -exec  du -hs {} +
```

Протестируйте команды, которые вы написали выше, для файлов и каталогов, в именах которых содержатся пробелы и специальные символы, такие как `!` и `&`.


Используя команду `grep`:

Из файла `/var/log/messages` вывести строки, содержащие ключевое слово `ERROR`, без учёта регистра.

```sh
grep -i ERROR /var/log/messages
```

Из файла `/var/log/messages` вывести **количество** строк, **не** содержащих ключевое слово `ERROR`, без учёта регистра.

```sh
sudo grep -i -c -v ERROR /var/log/messages
```

Из файла `/var/log/messages` вывести строки, содержащие **только слово `ERROR` целиком**, с учётом регистра.

```sh
grep -w ERROR /var/log/messages
```

Вывести количество строк из файла `/etc/group`, совпадающих с шаблоном `wheel`.

```sh
grep -c wheel /etc/group
```

Найти во всех файлах из текущего каталога и вложенных подкаталогов строки, содержащие шаблон `#!bin/bash`.

```sh
grep -rF '#!bin/bash'
```

Изменить предыдущую команду таким образом, чтобы она выводила дополнительные 10 строк после каждого найденного шаблона.

```sh
grep -rF -A 10 '#!bin/bash'
```

Найти во всех файлах с расширением `sh` из текущего каталога и вложенных подкаталогов строки, содержащие слово `echo` **целиком**. В выводе команды `grep` найденные слова выделите цветом.

```sh
grep -r --color -w 'echo' "*.sh"
```

Измените предыдущую команду таким образом, чтобы команда grep отображала также имя файла и номер строки, в которой было обнаружено совпадение с шаблоном.

```sh
grep -rnH --color -w 'echo' *.sh
```


# Отчёт по лабораторной работе

Скопируйте данную лабораторную работу в виде файла Markdown на свой компьютер, и под каждым заданием напишите ответ.

```sh
git clone https://github.com/efanov/mephi.wiki.git
```

Получившийся файл загрузите в собственный репозиторий.

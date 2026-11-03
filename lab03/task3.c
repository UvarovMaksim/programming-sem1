#include <stdio.h>

#define BUFFER_SIZE 256

int main() {
    char str[BUFFER_SIZE];

    printf("Введіть речення/текст: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Помилка зчитування введення!\n");
        return 1;
    }

    // Ручне видалення символу нового рядка '\n'
    int len = 0;
    while (str[len] != '\0') {
        if (str[len] == '\n') {
            str[len] = '\0';
            break;
        }
        len++;
    }

    printf("Початковий текст: \"%s\"\n", str);

    // Рахуємо кількість слів, щоб уникнути видалення, якщо слів менше 3
    int word_count = 0;
    int in_word = 0;
    for (int k = 0; str[k] != '\0'; k++) {
        if (str[k] != ' ' && !in_word) {
            in_word = 1;
            word_count++;
        } else if (str[k] == ' ') {
            in_word = 0;
        }
    }

    // Якщо слів менше 3, за умовами завдання видаляти нічого або виводимо оригінал
    if (word_count < 3) {
        printf("Результат (текст занадто короткий для видалення першого та останнього): \"%s\"\n", str);
        return 0;
    }

    // 1. Пропускаємо початкові пробіли
    int start_idx = 0;
    while (str[start_idx] == ' ' && str[start_idx] != '\0') {
        start_idx++;
    }

    // 2. Знаходимо кінець першого слова
    int first_word_end = start_idx;
    while (str[first_word_end] != ' ' && str[first_word_end] != '\0') {
        first_word_end++;
    }
    while (str[first_word_end] == ' ' && str[first_word_end] != '\0') {
        first_word_end++;
    }

    // 3. Зсуваємо решту тексту вліво
    int i = 0, j = first_word_end;
    while (str[j] != '\0') {
        str[i] = str[j];
        i++;
        j++;
    }
    str[i] = '\0';

    // 4. Знаходимо та видаляємо останнє слово
    int current_len = 0;
    while (str[current_len] != '\0') {
        current_len++;
    }

    int end_idx = current_len - 1;
    while (end_idx >= 0 && str[end_idx] == ' ') {
        end_idx--;
    }

    int last_word_start = end_idx;
    while (last_word_start >= 0 && str[last_word_start] != ' ') {
        last_word_start--;
    }
    last_word_start++;

    int cut_pos = last_word_start;
    while (cut_pos > 0 && str[cut_pos - 1] == ' ') {
        cut_pos--;
    }
    str[cut_pos] = '\0';

    printf("Текст після видалення першого та останнього слова (Варіант 14): \"%s\"\n", str);

    return 0;
}
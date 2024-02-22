Проект CI/CD "DO6_CICD" представляет собой последовательность этапов настройки и автоматизации процесса непрерывной интеграции и доставки (CI/CD) программного обеспечения с использованием GitLab Runner.

## Часть 1: Настройка GitLab Runner

Настраиваем виртуальную машину Ubuntu Server 22.04 LTS, устанавливает и регистрирует GitLab Runner для использования в проекте.
## Часть 2: Сборка

Внедрение этапа CI для сборки приложений из проекта C2_SimpleBashUtils с использованием make-файла. Артефакты сборки сохраняются на 30 дней.
## Часть 3: Тестирование кодстайла

Создание этапа CI для запуска скрипта кодстайла (clang-format). Пайплайн будет завершен с ошибкой, если код не соответствует стандартам.
## Часть 4: Интеграционное тестирование

Написание и выполнение интеграционных тестов из проекта C2_SimpleBashUtils. Этот этап автоматически запускается только после успешной сборки и прохождения тестов на кодстайл.
## Часть 5: Деплой

Настройка второй виртуальной машины Ubuntu Server 22.04 LTS и создание этапа CD для разворачивания приложения на ней. Деплой осуществляется вручную после успешного завершения предыдущих этапов.
## Часть 6: Дополнительно. Уведомления

Конфигурирование уведомлений о статусе пайплайна через Telegram бота с информацией об успешности прохождения этапов CI и CD.

Цель проекта состоит в автоматизации процессов сборки, тестирования и доставки программного обеспечения, обеспечивая стабильность и качество выпускаемых продуктов.
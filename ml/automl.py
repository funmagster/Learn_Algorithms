# # Рекомендуется создать виртуальное окружение
# pip install -U pip
# pip install autogluon
# # или установить только табличную часть (меньше зависимостей):
# # pip install autogluon.tabular

# tabular_train.py
import pandas as pd
from autogluon.tabular import TabularPredictor

# 1) Загрузим данные (пример: csv)
train_data = pd.read_csv("train.csv")   # замените на ваш путь
test_data  = pd.read_csv("test.csv")

# 2) Укажите целевую колонку
target = "target_column_name"

# 3) Инициализируем и обучаем
predictor = TabularPredictor(label=target, eval_metric='accuracy', path="ag_models/").fit(
    train_data=train_data,
    time_limit=600,            # секунды: ограничение времени обучения
    presets='best_quality',    # быстрые варианты: 'medium_quality', 'best_quality', 'optimize_for_deployment'
    verbosity=3,
    # опционально: num_bag_folds=5, num_stack_levels=1
)

# 4) Оценим на тесте
perf = predictor.evaluate(test_data)
print("Оценка на тесте:", perf)

# 5) Предсказания
X_test = test_data.drop(columns=[target])
y_pred = predictor.predict(X_test)
probs  = predictor.predict_proba(X_test)

# 6) Сохранение/загрузка (AutoGluon сам кладет модели в path)
# чтобы загрузить позднее:
# from autogluon.tabular import TabularPredictor
# predictor = TabularPredictor.load("ag_models/")


#######

predictor = TabularPredictor(label=target, path="ag_models_hpo/").fit(
    train_data=train_data,
    time_limit=3600,
    presets='best_quality',
    hyperparameters={  # пример: только некоторые типы моделей и их параметры
        'GBM': {'num_boost_round': 1000, 'learning_rate': 0.05},
        'CAT': {'iterations': 200},
        'NN': {'epochs': 20},
    },
    num_bag_folds=5,        # bagging
    num_stack_levels=1,     # stacking
    verbosity=3
)

#######3

import pandas as pd
from autogluon.tabular import TabularPredictor

# 1) Загружаем данные
train_data = pd.read_csv("train.csv")
test_data  = pd.read_csv("test.csv")

# Укажите свою колонку-цель
target = "price"   # например, прогноз стоимости

# 2) Инициализация + обучение
predictor = TabularPredictor(
    label=target,
    problem_type='regression',     # ← ключевое отличие!
    eval_metric='rmse',            # популярные метрики: rmse, mae, r2
    path="ag_regression_models/"
).fit(
    train_data=train_data,
    time_limit=600,                # ограничение по времени
    presets='best_quality',        # качество > скорость
    verbosity=3
)

# 3) Оценка качества
performance = predictor.evaluate(test_data)
print("Качество модели:", performance)

# 4) Предсказание
X_test = test_data.drop(columns=[target])
preds = predictor.predict(X_test)
print(preds.head())

# 5) (Необяз.) Предсказание с вероятностным распределением
# для регрессии — квантили (если нужно)
quantiles = predictor.predict_quantiles(X_test)
print(quantiles.head())

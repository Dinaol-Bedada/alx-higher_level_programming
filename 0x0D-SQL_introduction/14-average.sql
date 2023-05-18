-- Compute the average score of all records in the `second_table` table.
SELECT AVG(`score` /*[ DISTINCT | ALL ] EXPR*/) AS `average`
FROM `second_table`;

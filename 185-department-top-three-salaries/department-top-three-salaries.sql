SELECT d.name department
    , edr.name employee
    , edr.salary
 FROM (SELECT e.departmentid
            , e.salary
            , e.name
            , dense_rank() OVER (PARTITION BY e.departmentid ORDER BY e.salary DESC) dr
         FROM employee e) edr
 JOIN department d ON d.id = edr.departmentid
                  AND edr.dr <= 3;
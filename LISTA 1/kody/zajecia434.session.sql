-- 1
SELECT staff.first_name, staff.last_name, staff.email, address.address, address.phone 
FROM sakila.staff INNER JOIN sakila.address USING(address_id)
-- 2

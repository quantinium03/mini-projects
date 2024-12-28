-- name: UpdateCounter :one
update counter set counter = ? where id = 1 returning counter;

-- name: GetCounter :one
select counter from counter where id = 1;

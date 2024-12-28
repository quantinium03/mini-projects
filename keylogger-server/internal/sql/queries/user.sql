-- name: GetUserHash :one
select userhash from user where username = ?;

-- name: InsertUser :one
insert into user (username, userhash, updatedAt, createdAt) values (?, ?, ?, ?) returning *;

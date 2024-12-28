-- +goose Up
create table user (
    id integer primary key autoincrement,
    username text not null,
    userhash text not null,
    updatedAt datetime not null,
    createdAt datetime not null
);

-- +goose Down
drop table user;

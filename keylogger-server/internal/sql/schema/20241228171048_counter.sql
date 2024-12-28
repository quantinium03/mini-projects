-- +goose Up
-- +goose StatementBegin
create table counter (
    id int primary key,
    counter int not null default 0
);

insert into counter (id, counter) values (1, 0) on conflict do nothing;
-- +goose StatementEnd

-- +goose Down
-- +goose StatementBegin
drop table counter;
-- +goose StatementEnd

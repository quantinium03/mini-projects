package tp

import "github.com/mini-projects/keylogger-server/internal/database"

type ApiConf struct {
	DB *database.Queries
}

type CounterParameters struct {
	Counter int64 `json:"counter"`
}

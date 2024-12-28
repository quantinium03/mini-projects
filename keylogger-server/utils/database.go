package utils

import (
	"time"

	"github.com/mini-projects/keylogger-server/internal/database"
)

type User struct {
	Username string `json:"username"`
	Password string `json:"password"`
	CreatedAt time.Time	`json:"created_at"`
	UpdatedAt time.Time `json:"updated_at"`
}

func DatabaseUserToUser(user database.User) User {
	return User{
		Username: user.Username,
		Password: user.Userhash,
		CreatedAt: user.Createdat,
		UpdatedAt: user.Updatedat,
	}
}

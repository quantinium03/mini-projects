package mysql

import (
	"database/sql"
	"github.com/QuantiniumX/mini-projects/web_server/pkg/models"
)

type SnippetModel struct {
	DB *sql.DB
}

func (m *SnippetModel) Insert(title, content, expires string) (int, error) {
	return 0, nil
}

func (m *SnippetModel) Get(id int) (*models.Snippet, error) {
	return nil, nil
}

func(m* SnippetModel) latest() ([]*models.Snippet, error) {
    return nil, nil
}

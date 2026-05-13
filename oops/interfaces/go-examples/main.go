package main

import "fmt"

type NotificationService interface {
	Send(recipient string, message string)
}

type EmailNotifier struct{}

func (e *EmailNotifier) Send(recipient string, message string) {
	fmt.Printf("[Email] To: %s | %s\n", recipient, message)
}

type SlackNotifier struct{}

func (s *SlackNotifier) Send(recipient string, message string) {
	fmt.Printf("[Slack] Channel: %s | %s\n", recipient, message)
}

type WebhookNotifier struct{}

func (w *WebhookNotifier) Send(recipient string, message string) {
	fmt.Printf("[Webhook] URL: %s | %s\n", recipient, message)
}

type AlertService struct {
	notifier NotificationService
}

func NewAlertService(notifier NotificationService) *AlertService {
	return &AlertService{notifier: notifier}
}

func (a *AlertService) TriggerAlert(recipient string, issue string) {
	alertMessage := "ALERT: " + issue
	a.notifier.Send(recipient, alertMessage)
}

func main() {
	emailAlerts := NewAlertService(&EmailNotifier{})
	emailAlerts.TriggerAlert("ops@company.com", "CPU usage at 95%")

	slackAlerts := NewAlertService(&SlackNotifier{})
	slackAlerts.TriggerAlert("#incidents", "Database connection pool exhausted")

	webhookAlerts := NewAlertService(&WebhookNotifier{})
	webhookAlerts.TriggerAlert("https://hooks.example.com/alerts", "Disk usage at 90%")
}

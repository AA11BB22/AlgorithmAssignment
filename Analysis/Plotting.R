require(ggplot2)

data <- read.csv(file = "Report.txt", header = TRUE)

ggplot(data, aes(x = length.of.text)) + 
    geom_point(aes(y = Boyer.Moore, colour = "Boyer-Moore"), alpha=0.1) +
    geom_point(aes(y = Naive, colour = "Naive"), alpha = 0.1) +
    geom_smooth(aes(y = Boyer.Moore), method = "lm", se = FALSE, color = "cyan", size = 2) +
    geom_smooth(aes(y = Naive), method = "lm", se = FALSE, color = "orange", size = 2) +
    scale_colour_manual(values = c("blue", "red")) +
    ylab("Time taken, microseconds") +
    xlab("Length of text, n") + 
    ggtitle("Naive Method vs Boyer-Moore's Method")

dev.copy(png, filename = "Graph.png")
dev.off()